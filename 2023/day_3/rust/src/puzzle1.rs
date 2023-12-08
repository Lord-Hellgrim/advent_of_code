fn is_symbol(x: u8) -> bool {
    if x > 47 && x <= 58 {
        return false;
    } else if x == 46 {
        return false;
    } else {
        return true;
    }
}

fn adder(numbers: Vec<u8>) -> usize {
    let mut sum: usize = 0;
    let mut p = 1;
    let mut i = numbers.len()-1;
    while i > 0 {
        sum += numbers[i] as usize * p;
        i -= 1;
        p *= 10;
    }
    sum += numbers[0] as usize * p;
    sum

}


fn main() {
    let input = std::fs::read_to_string("puzzle_input.txt").unwrap();

    let mut machine = Vec::new();
    let mut i = 0;
    for line in input.lines() {
        machine.push(Vec::new());
        for char in line.chars() {
            machine[i].push(char as u8);
        }
        i += 1;
    }

    let mut sum = 0;

    let mut col = 0;
    while col < machine.len() {
        let mut row = 0;
        while row < machine[col].len() {
            // print!("{}", machine[col][row] as char);
            match machine[col][row] {
                48..=57 => {
                    let mut numbers = Vec::new();
                    numbers.push(machine[col][row]-48);
                    let mut incr = 1;
                    if row == 139 {
                        break;
                    }
                    while machine[col][row+incr] >= 48 && machine[col][row+incr] <= 57 {
                        numbers.push(machine[col][row+incr]-48);
                        incr += 1;
                        if row + incr > 139 {
                            break;
                        }
                    }
                    println!("{}", adder(numbers.clone()));
                    
                    let mut x: i32 = -1;
                    'outer: while x <= incr as i32 {
                        if x + (row as i32) < 0 {
                            x += 1;
                            continue;
                        } else if x + (row as i32) > 139 {
                            x += 1;
                            continue;
                        }
                        for y in -1..=1 {
                            if y + (col as i32) < 0 {
                                continue;
                            } else if y + (col as i32) > 139 {
                                continue;
                            }
                            println!("symbol: ({},{}) {}",y, x, machine[(col as i32 + y) as usize][(row as i32 + x) as usize] as char);
                            if is_symbol(machine[(col as i32 + y) as usize][(row as i32 + x) as usize]){
                                println!("number!: {}", adder(numbers.clone()));
                                sum += adder(numbers);
                                break 'outer;
                            }
                        }
                        x += 1;
                    }
                    row += incr;
                    
                    continue;
                },
                _ => (),
            }
            row += 1;
        }
        col += 1;
    }
    println!("sum: {}", sum);

}
