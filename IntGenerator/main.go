package main

import "fmt"

func main() {
	var e  map[int]int
	e = make(map[int]int)
	for i := 0; i < 100; i = i + 1 {
		e[i] = i;
	}
	for k, v := range e {
		fmt.Println(k,v)
	}
}
