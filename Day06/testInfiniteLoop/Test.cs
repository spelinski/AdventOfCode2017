using NUnit.Framework;
using System;
using infiniteLoopFinder;
using System.Collections.Generic;

namespace testInfiniteLoop
{
	[TestFixture ()]
	public class Test
	{
		[Test ()]
		public void singleIteration ()
		{
			LoopFinder myLoopFinder = new LoopFinder(new List<int>(){0,2,7,0});
			List<int> firstLoopResult = myLoopFinder.NextPass ();
			Assert.AreEqual (new List<int>(){2,4,1,2},firstLoopResult);
		}

		[Test ()]
		public void fiveStepsToInfinite()
		{
			LoopFinder myLoopFinder = new LoopFinder(new List<int>(){0,2,7,0});
			int stepsToInfinite = myLoopFinder.FindInfinite ();
			Assert.AreEqual (5,stepsToInfinite);
		}
	}
}

