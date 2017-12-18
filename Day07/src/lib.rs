use std::env;
use std::fs::File;
use std::io::prelude::*;

pub fn find_bottom(filename: String) -> String {
    println!("In file {}", filename);

    let mut f = File::open(filename).expect("file not found");

    let mut contents = String::new();
    f.read_to_string(&mut contents)
        .expect("something went wrong reading the file");

    println!("With text:\n{}", contents);
    "abcd".to_string()
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn testing_find_bottom() {
        assert_eq!("tknk".to_string(),find_bottom("test_data.txt".to_string()));
    }
}
