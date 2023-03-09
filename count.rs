use std::io::{BufRead, BufReader};
use std::fs::File;
use std::collections::HashMap;


fn main() {
    let filename = std::env::args().nth(1).expect("no filename given.");

    let mut words: HashMap<String, u32> = HashMap::new();

    let reader = BufReader::new(File::open(filename).expect("Cannot open file.txt"));
    for line in reader.lines() {
        for word in line.unwrap().split_whitespace() {
            *words.entry(word.to_string().to_lowercase()).or_insert(0) += 1;
        }
    }

    let mut count_vec: Vec<_> = words.iter().collect();
    count_vec.sort_by(|a, b| b.1.cmp(a.1));
    count_vec.iter().for_each(|it| {
        println!("{}: {}", it.0, it.1)
    })

}