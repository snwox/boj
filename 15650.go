package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func back(k int) {
	if k == M {
		for i := 0; i < M; i++ {
			writer.WriteString(strconv.Itoa(ar[i]) + " ")
		}
		writer.WriteByte('\n')
		return
	}

	for i := 1; i <= N; i++ {
		if used[i] == 0 {
			if k > 0 {
				if i > ar[k-1] {
					used[i] = 1
					ar[k] = i
					back(k + 1)
					used[i] = 0
				}
			} else {
				used[i] = 1
				ar[k] = i
				back(k + 1)
				used[i] = 0
			}
		}
	}
}

var N, M int
var ar, used [10]int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	bytes, _, _ := reader.ReadLine()
	line := string(bytes)

	nums := strings.Fields(line)

	N, _ = strconv.Atoi(nums[0])

	M, _ = strconv.Atoi(nums[1])
	defer writer.Flush()
	back(0)
}
