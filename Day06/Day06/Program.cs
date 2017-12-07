using System;
using infiniteLoopFinder;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Linq;

namespace Day06
{
	class MainClass
	{
		static void Main() {
			string line;
			System.IO.StreamReader file = new System.IO.StreamReader (@"../../challenge_one.txt");
			if ((line = file.ReadLine ()) != null) {
				List<int> banks = Regex.Split (line, @"\s+").Select(int.Parse).ToList();
				LoopFinder myLoopFinder = new LoopFinder(banks);
				int stepsToInfinite = myLoopFinder.FindInfinite ();
				Console.WriteLine ("Challenge One");
				Console.WriteLine (stepsToInfinite);

			}
			file.Close ();
		}
	}
}
