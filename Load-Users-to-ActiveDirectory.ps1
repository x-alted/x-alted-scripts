Import-Module ActiveDirectory
$users = Import-Csv "Z:\user_load.csv"

foreach ($user in $users) {
    $username = $user.username
    $firstname = $user.'first name'
    $lastname = $user.'last name'
    $id = $user.'id number'

    if (-not (Get-ADUser -Filter "SamAccountName -eq '$username'")) {
        New-ADUser -SamAccountName $username `
                   -GivenName $firstname `
                   -Surname $lastname `
                   -EmployeeID $id `
                   -Path "OU=Users,DC=progexp2025,DC=com" `
                   -AccountPassword (ConvertTo-SecureString "Passw0rd!!" -AsPlainText -Force) `
                   -ChangePasswordAtLogon $true -Enabled $true

        Add-ADGroupMember -Identity "Users" -Members $username
    }
}
