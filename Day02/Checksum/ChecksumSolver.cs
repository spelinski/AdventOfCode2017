using System;
using System.Linq;
using System.Collections.Generic;

namespace Checksum
{
	public class ChecksumSolver
	{
		public ChecksumSolver ()
		{
		}

		public int findDiffRow(List<int> myRow)
		{
			int largestDiff = 0;
			foreach (int outerNum in myRow) {
				foreach (int innerNum in myRow) {
					if ((outerNum - innerNum) > largestDiff) {
						largestDiff = (outerNum - innerNum);
					}
				}
			}
			return largestDiff;
		}

		public int findDivisibleRow(List<int> myRow)
		{
			
			for (int i = 0; i < myRow.Count; i++) {
				for (int j = 0; j < myRow.Count; j++) {
					if (i != j) {
						float divisionResult = (float)myRow[i] / (float)myRow[j];
						if (divisionResult == Math.Floor (divisionResult)) {
							return (int)divisionResult;
						}
						divisionResult = (float)myRow[j] / (float)myRow[i];
						if (divisionResult == Math.Floor (divisionResult)) {
							return (int)divisionResult;
						}
					}
				}
			}
			return 0;
		}
	}
}

