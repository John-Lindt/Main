#!/bin/bash
echo "Enter a directory"
read Search
if [ -d "$Search" ]; then
$Search ls -l | grep src.* *src*.* | wc -l	
fi
else
	echo "Error: ${Search} not found."
fi