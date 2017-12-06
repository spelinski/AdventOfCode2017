import unittest
import instruction_follower


class TestInstructionFollower(unittest.TestCase):
    def test_five_steps(self):
        num_steps = instruction_follower.find_num_steps_exit(["0","3","0","1","-3"],False);
        self.assertEqual(num_steps, 5)

    def test_challenge_two(self):
        num_steps = instruction_follower.find_num_steps_exit(["0", "3", "0", "1", "-3"], True);
        self.assertEqual(num_steps, 10)




if __name__ == '__main__':
    unittest.main()
