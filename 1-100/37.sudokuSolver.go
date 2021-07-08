package main

import "fmt"

func main() {
	/* 	board := [][]byte{
	   		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	   		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	   		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	   		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	   		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	   		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	   		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	   		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	   		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	   	}
	*/
	board := [][]byte{
		{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
		{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '2', '.', '1', '.', '9', '.', '.', '.'},
		{'.', '.', '7', '.', '.', '.', '2', '4', '.'},
		{'.', '6', '4', '.', '1', '.', '5', '9', '.'},
		{'.', '9', '8', '.', '.', '.', '3', '.', '.'},
		{'.', '.', '.', '8', '.', '3', '.', '2', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '6'},
		{'.', '.', '.', '2', '7', '5', '9', '.', '.'},
	}
	solveSudoku(board)
	fmt.Println("-------")
	for _, row := range board {

		for _, col := range row {
			fmt.Print("|", string(col))
		}
		fmt.Println("|")
	}

}

var (
	rowValMap = [10][10]int{}
	colValMap = [10][10]int{}
	sboxMap   = [10][10]int{}
)

func solveSudoku(board [][]byte) {
	for rowIdx, row := range board {
		for colIdx, col := range row {
			if col != '.' {
				intVal := int(col - '0')
				sboxIdx := (rowIdx/3)*3 + colIdx/3
				rowValMap[rowIdx][intVal] = 1
				colValMap[colIdx][intVal] = 1
				sboxMap[sboxIdx][intVal] = 1
			}
		}
	}

	solveSudokuRecursion(board, 0, 0)

}

func solveSudokuRecursion(board [][]byte, rowIdx, colIdx int) bool {

	incrRow := 0
	nextColIdx := colIdx
	if colIdx == 8 {
		incrRow = 1
		nextColIdx = 0
	} else {
		nextColIdx += 1
	}
	if rowIdx == 9 {
		return true
	}
	nextRowIdx := rowIdx + incrRow

	if board[rowIdx][colIdx] != '.' {
		return solveSudokuRecursion(board, nextRowIdx, nextColIdx)
	}

	sboxIdx := (rowIdx/3)*3 + colIdx/3

	for val := 1; val < 10; val++ {

		if rowValMap[rowIdx][val] == 1 || colValMap[colIdx][val] == 1 || sboxMap[sboxIdx][val] == 1 {
			continue
		} else {
			rowValMap[rowIdx][val] = 1
			colValMap[colIdx][val] = 1
			sboxMap[sboxIdx][val] = 1
			if solveSudokuRecursion(board, nextRowIdx, nextColIdx) {

				board[rowIdx][colIdx] = '0' + byte(val)
				return true
			}

			rowValMap[rowIdx][val] = 0
			colValMap[colIdx][val] = 0
			sboxMap[sboxIdx][val] = 9

		}

	}

	return false

}
