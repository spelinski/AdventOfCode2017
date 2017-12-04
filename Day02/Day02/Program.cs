using System;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using Checksum;

namespace Day02
{
	class MainClass
	{
		static void Main() {
			string line;
			ChecksumSolver mcs = new ChecksumSolver ();
			List<int> resultOfRowsDiff = new List<int> ();
			List<int> resultOfRowsDiv = new List<int> ();
			System.IO.StreamReader file = new System.IO.StreamReader (@"../../challenge_one.txt");
			while ((line = file.ReadLine ()) != null) {
				List<int> row = Regex.Split (line, @"\s+").Select(int.Parse).ToList();
				resultOfRowsDiff.Add (mcs.findDiffRow (row));
				resultOfRowsDiv.Add (mcs.findDivisibleRow (row));
			}
			file.Close ();
			Console.WriteLine ("Challenge One");
			Console.WriteLine (resultOfRowsDiff.Sum());
			Console.WriteLine ("Challenge Two");
			Console.WriteLine (resultOfRowsDiv.Sum ());
		}
	}
}
