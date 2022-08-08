package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type xy struct {
	x float64
	y float64
}

var r = bufio.NewReader(os.Stdin)
var w = bufio.NewWriter(os.Stdout)
var N, M int
var board [50][50]int
var house = make([]xy, 0, 13)
var chicken = make([]xy, 0, 13)
var tmp [2500]xy
var used [2500]bool
var max float64 = 0xffffffff

/*
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2 -> 5
*/

/*
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2 -> 10
*/

func back(n, idx int) {
	if idx > len(chicken) {
		return
	}
	if n == M {
		sum := 0.0
		for _, h := range house {
			min := float64(0xffffffff)
			for i := 0; i < len(chicken); i++ {
				if used[i] {
					c := chicken[i]
					min = math.Min(math.Abs(h.x-c.x)+math.Abs(h.y-c.y), min)
				}
			}
			sum += min
		}
		max = math.Min(sum, max)
		return
	}
	used[idx] = true
	back(n+1, idx+1)
	used[idx] = false
	back(n, idx+1)
}
func main() {
	defer w.Flush()
	fmt.Fscan(r, &N, &M)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Fscan(r, &board[i][j])
			if board[i][j] == 1 {
				house = append(house, xy{float64(i), float64(j)})
			}
			if board[i][j] == 2 {
				chicken = append(chicken, xy{float64(i), float64(j)})
			}
		}
	}
	back(0, 0)
	fmt.Fprintln(w, max)
}
