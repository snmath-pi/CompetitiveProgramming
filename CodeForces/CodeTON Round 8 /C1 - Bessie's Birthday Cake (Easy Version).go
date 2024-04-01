package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func nextInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func solve() {
	n := nextInt()
	x := nextInt()
	y := nextInt()

	a := make([]int, x)

	for i := 0; i < x; i++ {
		a[i] = nextInt()
	}

	sort.Ints(a)

	cnt := 0

	for i := 0; i < x-1; i++ {
		if a[i+1]-a[i] == 2 {
			cnt++
		}
	}
	if a[0]-2 + n + y-y == a[x-1] {
		cnt++
	}
	fmt.Fprintln(writer, x-2+cnt)
}

func main() {
	t := nextInt()
	for i := 0; i < t; i++ {
		solve()
	}
	writer.Flush()
}
