

func SearchMatrix(matrix [][]int, len int ) {
	matrixLen := 0
	for row := 0; row < len; row ++ {
		if col := 0; col < len; col ++ {
			if matrix[row][col] == 0 {
				continue 
			}

		}
		itemMatrixLen := 1
		for ; SearchMatrixNode(matrix, row, col, itemMatrixLen);  {
			itemMatrixLen++
		}
		if itemMatrixLen > matrixLen {
			matrixLen = itemMatrixLen
		}
		


	}
}

func SearchMatrixNode(matrix [][]int, len int , row, col, matrixLen int) bool {
  
	endPointRow := row + matrixLen 
	endPointCol := col + matrixLen
	for idx := col; idx < matrixLen; idx ++ {
		if matrix[endPointRow][idx] == 0 {
			return false 
		}
	}

	for idx := row; idx < row; idx ++ {
		if matrix[row][endPointCol] == 0 {
			return false 
		}
	}	

}