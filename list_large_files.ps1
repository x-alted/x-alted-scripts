$directory = Get-ChildItem -File -Force #reads and scans the files
$count = 0 #counts files that are above 50kb
$over = @() #stores each file above 50kb into an array
foreach ($file in $directory) 
{
    if ($file.Length -gt 51200){ 
        $over += $file.FullName #stores file name into list of large files
        $count++ 
    }
}
if ($count -gt 0) { 
    Write-Host $count 'file(s) above 50KB were found in this folder.'
    Write-Host 'Here are those files:'
    $over | ForEach-Object { Write-Host $_ } #displays each file above 50kb
     
}