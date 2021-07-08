package main

import (
	"fmt"
	"sort"
)

func main() {
	m := []int{4, 3, 6, 4}
	n := []int{5, 5, 8, 7}
	k := 15
	fmt.Println(maxSum(m, n, k))

}

func maxSum(m, n []int, k int) int {

	pMap := make(map[int][]int, 0)
	for idx := range m {
		p := (n[idx] * 100) / m[idx]
		pMap[p] = append(pMap[p], idx)
	}

	pList := []int{}
	for p := range pMap {
		pList = append(pList, p)
	}
	sort.Ints(pList)

	sum := k
	for _, p := range pList {

		idxs := pMap[p]
		cnt := len(idxs)

		for row := 0; row < cnt-1; row++ {
			min := m[idxs[row]]
			for col := row + 1; col < cnt; col++ {
				if min > m[idxs[col]] {
					min = m[idxs[col]]
					idxs[row], idxs[col] = idxs[col], idxs[row]
				}
			}
		}
		for idx := range idxs {
			buyCnt := sum / m[idx]
			if buyCnt == 0 {
				continue
			}

			sum = buyCnt*(n[idx]-m[idx]) + sum
			fmt.Println(buyCnt, sum)
		}

	}

	return sum - k
}
