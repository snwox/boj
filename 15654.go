package main

import (
	"bufio"
	"os"
	"sort"
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

	for i := 0; i < N; i++ {
		if k > 0 {
			if numbers[i] > ar[k-1] {
				ar[k] =  numbers[i]
				back(k + 1)
			}
		} else {
			ar[k] = numbers[i]
			back(k + 1)
		}
	}
}

var N, M int
var ar,numbers []int
var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	bytes, _, _ := reader.ReadLine()
	nums := strings.Fields(string(bytes))
	N, _ = strconv.Atoi(nums[0])
	M, _ = strconv.Atoi(nums[1])
	bytes, _, _ = reader.ReadLine()
	nums = strings.Fields(string(bytes))
	ar=make([]int,N)
	numbers=make([]int,N)
	for i:=0;i<N;i++{
		numbers[i],_ = strconv.Atoi(nums[i])
	}
	sort.Ints(numbers)
	defer writer.Flush()
	back(0)
}
