$directory = Get-ChildItem -File #retrieves files from source directory
$count = 0 #counts the files 
$over = @() #stores each file above 50kb into an array
foreach ($file in $directory) #for each file in the directory...
{
    if ($file.Length -gt 51200){ #if the file is over 50kb...
        Write-Host "File $($file.FullName)"#outputs current file path being scanned 
        Write-Host "Size: $((($file.Length / 1024).ToString('F0'))) KB"
            #round bytes to nearest int value
            #converts byte value into a string
            #displays file size 
        $over += $file.FullName #stores file name into the array
        $count++ #increment file count by one for each loop
    }
}
if ($count -gt 0) { #if count is higher than 0...
    Write-Host $count 'file(s) above 50KB were found in this directory.' #display count 
    Write-Host 'Here are those files:'
    $over | ForEach-Object { Write-Host $_ } #displays each file above 50kb
}
else { #if count is 0
    Write-Host 'There is no file larger than 50KB in this directory.'
}