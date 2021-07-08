package main

import "fmt"

func main() {

	fmt.Println("2", longestValidParentheses("(()"))

	fmt.Println("4", longestValidParentheses(")()())"))

	fmt.Println("2", longestValidParentheses("()(()"))
	fmt.Println("12", longestValidParentheses("()(()()(()))"))

}

func longestValidParentheses(s string) int {
	var leftCntArr []int
	maxLen := 0
	curLen := 0
	for _, c := range s {
		if c == '(' {
			if curLen > maxLen {
				maxLen = curLen
			}
			leftCntArr = append(leftCntArr, curLen)
			curLen = 0
			continue
		} else {
			if len(leftCntArr) == 0 {
				if curLen > maxLen {
					maxLen = curLen
				}
				curLen = 0
				continue
			} else {
				leftCntArrLen := len(leftCntArr)
				lastVal := leftCntArr[leftCntArrLen-1]

				leftCntArr = leftCntArr[:leftCntArrLen-1]
				curLen += 1 + lastVal
			}
		}

	}

	if curLen > maxLen {
		maxLen = curLen
	}

	return maxLen + maxLen

}
