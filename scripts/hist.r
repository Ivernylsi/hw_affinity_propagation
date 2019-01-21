data <- read.table("heights.txt", header=FALSE, dec=",")

print(data[,1])
data <- as.numeric(data[,1])
hist(data, 100)
