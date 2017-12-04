using NUnit.Framework;
using System;
using System.Linq;
using System.Collections.Generic;
using Checksum;

namespace ChecksumTest
{
	[TestFixture ()]
	public class Test
	{
		[Test ()]
		public void rowWithDiffEight ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){5,1,9,5};
			iList.Add (5);
			iList.Add (1);
			iList.Add (9);
			iList.Add (5);
			int result = mcs.findDiffRow(iList);
			Assert.AreEqual (8, result);
		}
		[Test ()]
		public void rowWithDiffFour ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){7,5,3};
			int result = mcs.findDiffRow(iList);
			Assert.AreEqual (4, result);
		}
		[Test ()]
		public void rowWithDiffSix ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){2,4,6,8};
			int result = mcs.findDiffRow(iList);
			Assert.AreEqual (6, result);
		}
		[Test ()]
		public void rowWithDivisionFour ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){5,9,2,8};
			int result = mcs.findDivisibleRow (iList);
			Assert.AreEqual (4, result);
		}
		[Test ()]
		public void rowWithDivisionThree ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){9,4,7,3};
			int result = mcs.findDivisibleRow (iList);
			Assert.AreEqual (3, result);
		}
		[Test ()]
		public void rowWithDivisionTwo ()
		{
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> iList = new List<int> (){3,8,6,5};
			int result = mcs.findDivisibleRow (iList);
			Assert.AreEqual (2, result);
		}

	}
}

