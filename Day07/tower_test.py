import unittest
from tower_builder import Tower_builder


class TestTower(unittest.TestCase):
    def test_sample_input_from_challenge(self):
        file = open("challenge_sample.txt", "r")
        my_programs = file.readlines()
        file.close()
        my_tower_builder = Tower_builder(my_programs)
        bottom = my_tower_builder.find_bottom()
        self.assertEqual(bottom, "tknk")

    def test_challenge_one_input_from_challenge(self):
        file = open("challenge_one_input.txt", "r")
        my_programs = file.readlines()
        file.close()
        my_tower_builder = Tower_builder(my_programs)
        bottom = my_tower_builder.find_bottom()
        self.assertEqual(bottom, "azqje")

    def test_sample_input_for_challenge_two(self):
        file = open("challenge_sample.txt", "r")
        my_programs = file.readlines()
        file.close()
        my_tower_builder = Tower_builder(my_programs)
        change_needed = my_tower_builder.get_weight_needed()
        self.assertEqual(change_needed, 60)


if __name__ == '__main__':
    unittest.main()

