package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

var N, M int
var ar [10]int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func back(k int) {
	if k == M {
		for i := 0; i < M; i++ {
			writer.WriteString(strconv.Itoa(ar[i]) + " ")
		}
		writer.WriteString("\n")
		return
	}

	for i := 1; i <= N; i++ {
		ar[k] = i
		back(k + 1)
	}
}

func main() {
	bytes, _, _ := reader.ReadLine()

	line := string(bytes)

	nums := strings.Fields(line)

	N, _ = strconv.Atoi(nums[0])

	M, _ = strconv.Atoi(nums[1])
	defer writer.Flush()
	back(0)
}
