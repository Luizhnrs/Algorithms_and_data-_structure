fn main(){
    ex1()
}

fn ex1(){
    let mut x: i32 = 5;
    let mut z: &mut i32 = &mut x;

    z = 10;

    println("x:{}",x);
}