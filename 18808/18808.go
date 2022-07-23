package main

import (
	"bufio"
	"fmt"
	"os"
)

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)
var N, M, K, R, C int
var laptop [40][40]int
var sticker [10][10]int

func pasteable(x, y int) bool { // Do the stickers overlap?
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if laptop[i+x][j+y] == 1 && sticker[i][j] == 1 {
				return false
			}
		}
	}
	return true
}
func paste(x, y int) { // paste sticker to laptop (only 1, 0 erase sticker onlaptop )
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if sticker[i][j] == 1 {
				laptop[i+x][j+y] = sticker[i][j]
			}
		}
	}
}
func rotate() (int, int) { // sticker[j][R-1-i]=tmp[i][j]
	tmp := [10][10]int{}
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			tmp[i][j] = sticker[i][j]
		}
	}
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			sticker[j][R-1-i] = tmp[i][j]
		}
	}

	return C, R
}
func main() {
	defer w.Flush()
	fmt.Fscanln(r, &N, &M, &K)
	for i := 0; i < K; i++ {
		fmt.Fscan(r, &R, &C)
		for j := 0; j < R; j++ {
			for k := 0; k < C; k++ {
				fmt.Fscan(r, &sticker[j][k])
			}
		}
		for rot := 0; rot < 4; rot++ {
			flag := false
			for x := 0; x <= N-R; x++ {
				for y := 0; y <= M-C; y++ { // oob check
					if pasteable(x, y) {
						paste(x, y)
						flag = true // if find, must out the loop
						break
					}
				}
				if flag {
					break
				}
			}
			if flag {
				break
			}
			R, C = rotate()
		}
	}
	ans := 0
	for i := 0; i < N; i++ { // just count all sticker
		for j := 0; j < M; j++ {
			if laptop[i][j] == 1 {
				ans += 1
			}
		}
	}
	fmt.Fprintln(w, ans)
}
