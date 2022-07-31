package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)
var N int
var ar, ar2 [20][20]int

func tilt(dir int) { // rotate table and merge numbers
	tmp := [20][20]int{}
	for ; dir > 0; dir-- { // rotate
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				tmp[i][j] = ar2[i][j]
			}
		}
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				ar2[j][N-1-i] = tmp[i][j]
			}
		}
	}

	for i := 0; i < N; i++ {
		idx := 0
		for j := 0; j < N; j++ {
			if j != idx && ar2[i][j] != 0 {
				if ar2[i][idx] == 0 { // if zero, just put the number
					ar2[i][idx] = ar2[i][j]
					ar2[i][j] = 0
				} else if ar2[i][idx] == ar2[i][j] { // merge number
					ar2[i][idx] *= 2
					ar2[i][j] = 0
					idx += 1
				} else { // put the number into the next idx
					idx += 1
					ar2[i][idx] = ar2[i][j]
					if j != idx {
						ar2[i][j] = 0
					}
				}
			}
		}
	}

}

func main() {
	ans := -1

	defer w.Flush()
	fmt.Fscan(r, &N)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Fscan(r, &ar[i][j])
		}
	}

	for i := 0; i < 1024; i++ { // set the direction by 4 digit number
		for x, line := range ar {
			for y, v := range line {
				ar2[x][y] = v
			}
		}
		saved := i
		for j := 0; j < 5; j++ { // maximum move : 5
			dir := saved % 4
			saved /= 4
			tilt(dir)
		}
		for _, line := range ar2 { // find the max value
			for _, v := range line {
				if v > ans {
					ans = v
				}
			}
		}
	}
	fmt.Fprintln(w, ans)
}
