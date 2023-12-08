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

fn find_numbers(col: usize, row: usize, machine: &Vec<Vec<u8>>) -> Option<(usize, usize)> {
    println!("{},{}", col, row);
    let mut numbers = Vec::new();
    
    if machine[col-1][row-1] > 47 && 58 >= machine[col-1][row-1] {
        numbers.push(make_number(col-1, row-1, machine));
    }
    if machine[col-1][row] > 47 && 58 >= machine[col-1][row] {
        println!("top center: {}", machine[col-1][row]);
        numbers.push(make_number(col-1, row, machine));
    }
    if machine[col-1][row+1] > 47 && 58 >= machine[col-1][row+1] {
        numbers.push(make_number(col-1, row+1, machine));
    }
    if machine[col][row-1] > 47 && 58 >= machine[col][row-1] {
        numbers.push(make_number(col, row-1, machine));
    }
    if machine[col][row] > 47 && 58 >= machine[col][row] {
        numbers.push(make_number(col, row, machine));
    }
    if machine[col][row+1] > 47 && 58 >= machine[col][row+1] {
        numbers.push(make_number(col, row+1, machine));
    }
    if machine[col+1][row-1] > 47 && 58 >= machine[col+1][row-1] {
        numbers.push(make_number(col+1, row-1, machine));
    }
    if machine[col+1][row] > 47 && 58 >= machine[col+1][row] {
        numbers.push(make_number(col+1, row, machine));
    }
    if machine[col+1][row+1] > 47 && 58 >= machine[col+1][row+1] {
        numbers.push(make_number(col+1, row+1, machine));
    }
    numbers.dedup();
    println!("numbers: {:?}", numbers);

    if numbers.len() != 2 {
        return None
    }

    Some((numbers[0], numbers[1]))
}

fn make_number (col: usize, row: usize, machine: &Vec<Vec<u8>>) -> usize {
    
    let mut numbers = Vec::new();

    let mut incr: i32 = 0;
    loop{
        if row as i32 + incr as i32 - 1 < 0 {
            break;
        }
        if !(machine[col][(row as i32 + incr) as usize-1] >= 48 && machine[col][(row as i32 + incr) as usize-1] <= 57) {
            break;
        }
        incr -= 1
    }
    
    while machine[col][(row as i32 + incr) as usize] >= 48 && machine[col][(row as i32 + incr) as usize] <= 57 {
        numbers.push(machine[col][(row as i32 + incr) as usize]-48);
        incr += 1;
    }
    println!("adder: {}", adder(numbers.clone()));
    adder(numbers)
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
            // print!("{},{}", col, row);
            match machine[col][row] {
                42 => {
                    let number = find_numbers(col, row, &machine);
                    match number {
                        Some(num) => {
                            sum += num.0 * num.1;
                            println!("sum: {}", sum);
                        },
                        None => (),
                    }
                },
                _ => (),
            };
            row += 1;
        }
        col += 1;
    }
    println!("sum: {}", sum);

}
