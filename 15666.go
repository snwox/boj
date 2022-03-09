package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
	"strings"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var N,M int
var ar,numbers []int

func back(k,prev int){
	if k==M{
		// fmt.Println(ar)
		for i:=0;i<M;i++{
			writer.WriteString(strconv.Itoa(ar[i])+" ")
		}
		writer.WriteByte(0xa)
		return
	}
	temp:=-1
	for i:=prev;i<N;i++{
		if numbers[i] != temp{
			ar[k]=numbers[i]
			temp = numbers[i]
			back(k+1,i)
		}
	}
}
func main(){
	defer writer.Flush()
	bytes,_,_ := reader.ReadLine()
	nums:=strings.Fields(string(bytes))
	N,_ = strconv.Atoi(nums[0])
	M,_ = strconv.Atoi(nums[1])
	bytes,_,_ = reader.ReadLine()
	nums = strings.Fields(string(bytes))
	ar=make([]int, M,10)
	numbers=make([]int, N,10)
	for i,v := range nums{
		numbers[i],_=strconv.Atoi(v)
	}
	sort.Ints(numbers)
	back(0,0)
}