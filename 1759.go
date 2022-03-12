package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
	"strings"
)
var io = bufio.NewReadWriter(bufio.NewReader(os.Stdin),bufio.NewWriter(os.Stdout))
var L,C int
var ar []string
func back(k,c,v,prev int){
	if k==L{
		if c>1 && v>0{
			for _,c :=range ar{
				io.WriteString(c)
			}
			io.WriteByte('\n')
		}
		return
	}
	tmp:=""
	for i:=prev;i<C;i++{
		if numbers[i]!=tmp{
			ar[k]=numbers[i]
			switch numbers[i]{
				case
					"a",
					"e",
					"i",
					"o",
					"u":
					back(k+1,c,v+1,i+1)
				default:
					back(k+1,c+1,v,i+1)
			}
			tmp=numbers[i]
		}
	}
}

var numbers[]string
func main(){
	defer io.Flush()
	bytes,_,_ :=io.ReadLine()
	nums:=strings.Fields(string(bytes))
	L,_=strconv.Atoi(nums[0])
	C,_=strconv.Atoi(nums[1])
	numbers=make([]string,C,C)
	ar=make([]string,C,C)

	bytes,_,_ = io.ReadLine()
	numbers=strings.Fields(string(bytes))
	sort.Strings(numbers)
	back(0,0,0,0)
}