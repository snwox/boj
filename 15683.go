package main

import (
	"bufio"
	"fmt"
	"os"
)

type XY struct {
	x int
	y int
}

var dx = []int{-1, 0, 1, 0}
var dy = []int{0, 1, 0, -1}
var w = bufio.NewWriter(os.Stdout)
var r = bufio.NewReader(os.Stdin)
var N, M int
var board, board2 [10][10]int

func pad(x, y, dir int) {
	dir %= 4
	for 1 == 1 {
		x += dx[dir]
		y += dy[dir]
		if 0 > x || x >= N || 0 > y || y >= M || board2[x][y] == 6 { // reach the wall
			break
		}
		if board2[x][y] != 0 { // there is a cctv, able to get through
			continue
		}
		board2[x][y] = 7
	}
}

func main() {
	prev := 0
	var cctv []XY = make([]XY, 0, 8)
	defer w.Flush()
	fmt.Fscan(r, &N, &M)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			fmt.Fscan(r, &board[i][j])
			if board[i][j] == 0 {
				prev += 11
			} else if board[i][j] > 0 && board[i][j] < 6 {
				cctv = append(cctv, XY{i, j})
			}
		}
	}
	// fmt.Fprintln(w, cctv)
	// fmt.Fprint(w, board)
	for k := 0; k < 1<<(2*len(cctv)); k++ { // 4진수로 모든 방향 탐색
		ans := 0
		kk := k
		for i := range board {
			for j, value := range board[i] {
				board2[i][j] = value
			}
		}
		for c := 0; c < len(cctv); c++ { // 4진수 각 자리별로 cctv 의 방향을 나타냄
			dir := kk % 4
			kk /= 4
			x := cctv[c].x
			y := cctv[c].y
			switch board2[x][y] {
			case 1:
				pad(x, y, dir)
			case 2:
				pad(x, y, dir)
				pad(x, y, dir+2)
			case 3:
				pad(x, y, dir)
				pad(x, y, dir+1)
			case 4:
				pad(x, y, dir)
				pad(x, y, dir+1)
				pad(x, y, dir+2)
			case 5:
				pad(x, y, dir)
				pad(x, y, dir+1)
				pad(x, y, dir+2)
				pad(x, y, dir+3)
			}
		}
		// fmt.Fprintln(w, board2)
		for i := 0; i < N; i++ { // 0 개수 카운트
			for j := 0; j < M; j++ {
				if board2[i][j] == 0 {
					ans += 1
				}
			}
		}
		if ans < prev {
			prev = ans
			ans = prev
		}
	}
	fmt.Fprintln(w, prev)

}
