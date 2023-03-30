# take input from the user
#num = as.integer(readline(prompt="Enter a number: "))
cat("Please enter a number: ");
num <- as.integer(readLines("stdin",n=1));
f = 1
# check is the number is negative, positive or zero
if(num < 0) {
       print("Sorry, f negative numbers")
} else if(num == 0) {
  print("f 0 is 1")
} else {
  for(i in 1:num) {
    f = f * i
  }
  print(paste("f(", num ,") =",f))
}
