using System;
using System.Collections.Generic;
using System.Linq;

namespace infiniteLoopFinder
{
	public class LoopFinder
	{
		public LoopFinder (List<int> memory)
		{
			
			memoryBanks = memory;
			memoryBanks.ForEach (Console.WriteLine);
			Console.WriteLine ("gap");
			seenStates = new List<List<int>> ();
			seenStates.Add (new List<int> (memoryBanks));
		}
		List<int> memoryBanks;
		List<List<int>> seenStates;

		public List<int> NextPass()
		{
			if (memoryBanks.Any ()) {
				int indexMax = memoryBanks.IndexOf (memoryBanks.Max ());
				int numOfBlocks = memoryBanks [indexMax];
				memoryBanks [indexMax] = 0;
				int loopIndex = indexMax + 1;
				while (numOfBlocks > 0) {
					if (loopIndex >= memoryBanks.Count) {
						loopIndex = 0;
					}
					memoryBanks [loopIndex]++;
					loopIndex++;
					numOfBlocks--;
				}
			}
			return memoryBanks;
		}

		private bool duplicateDetected()
		{
			for (int i = 0; i < seenStates.Count; i++) {
				for (int j = i + 1; j < seenStates.Count; j++) {
					if (seenStates [i] == seenStates [j]) {
						return true;
					}
				}
			}
			return false;
		}

		public int FindInfinite()
		{
			int steps = 0;
			int loops = 0;
			while (!duplicateDetected ()) {
				steps++;
				seenStates.Add (new List<int> (NextPass()));
				if (loops % 1000 == 0) {
					Console.WriteLine (loops);
				}
				loops++;
			}
			for(int i=0; i < seenStates.Count; i++)
			{
				for (int j=0; j < seenStates[i].Count; j++)
				{
					Console.Write(seenStates[i][j]);
				}
				Console.WriteLine ("");
			}
			return steps;
		}
	}
}

