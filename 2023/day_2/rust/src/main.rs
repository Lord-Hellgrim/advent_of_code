use core::num;
use std::collections::HashMap;

fn main() {
    let input = std::fs::read_to_string("puzzle_input.txt").unwrap();

    let r = 12;
    let g = 13;
    let b = 14;
    
    let mut sum = 0;
    for game in input.lines() {
        println!("{}", game);
        let game_id = game.split(':').collect::<Vec<&str>>()[0].split(' ').collect::<Vec<&str>>()[1].parse::<u32>().unwrap(); 
        println!("\x1b[0;31mgame_id: {}\x1b[0m", game_id);
        let temp: &str = game.split(':').collect::<Vec<&str>>()[1];
        println!("temp: {}", temp);
        let sets: Vec<&str> = temp.split(';').collect();
        let mut min_red = 0 ;
        let mut min_green = 0;
        let mut min_blue = 0;
        for set in sets {
            println!("set: {}", set);
            for item in set.split(',') {
                // println!("item: {}", item);
                let color = item.split(' ').collect::<Vec<&str>>()[2];
                // println!("color: {}", color);
                let num_cubes = item.split(' ').collect::<Vec<&str>>()[1].trim().parse::<u32>().unwrap();
                match color {
                    "red" => min_red = std::cmp::max(min_red, num_cubes),
                    "green" => min_green = std::cmp::max(min_green, num_cubes),
                    "blue" => min_blue = std::cmp::max(min_blue, num_cubes),
                    _ => unreachable!(),
                }
                // println!("num_cubes: {}", num_cubes);
            }

        }
        println!("min r, g, b: {}, {}, {}", min_red, min_green, min_blue);
        let power = min_red * min_green * min_blue;
        sum += power;
        println!("sum: {}", sum);
    }


}
