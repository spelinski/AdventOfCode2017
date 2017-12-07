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

		private bool duplicateDetected(List<int> latestState)
		{
			foreach (List<int> oldState in seenStates) {
				if (oldState.SequenceEqual(latestState)) {
					return true;
				}
			}
			return false;
		}

		public Tuple<int,int> FindInfinite()
		{
			int steps = 0;
			int loops = 0;
			while (true) {
				steps++;
				List<int> tempBanks = new List<int> (NextPass ());
				if (duplicateDetected (tempBanks)) {
					int indexOfFirst = 0;
					for (int i = 0; i < seenStates.Count; i++) {
						if (seenStates [i].SequenceEqual (tempBanks)) {
							indexOfFirst = i;
							break;
						}
					}
					int sizeOfLoop = seenStates.Count - indexOfFirst;
					return Tuple.Create(steps,sizeOfLoop);
				}
				seenStates.Add (new List<int> (tempBanks));
				if (loops%1000 == 0) {
					Console.WriteLine (loops);
				}
				loops++;
			}
		}
	}
}

