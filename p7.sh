#Name: Aakash Bhavesh Patel
#Roll No.: MT2024109
#Problem 7, Write a program to copy file1 into file2 ($cp file1 file2).


source_file="$1"
destination_file="$2"


if [ ! -f "$source_file" ]; then
    echo "Error"
    exit 1
fi

cp "$source_file" "$destination_file"

if [ $? -eq 0 ]; then
    echo "Success"
else
    echo "Error"
    exit 1
fi
