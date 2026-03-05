#!/bin/bash

while true; do #loops until user no longer wants to guess
  random_no=$(( 1 + $RANDOM % 51 )) #find random number between 1 and 51
  attempts=3 #set number of attempts to 3

  echo "Can you guess the number? It's between 1 and 51!" #asks user to guess

  while [ $attempts -gt 0 ]; do #if attempt count is over 0, allow user to enter guess
    echo -n "Enter your guess: " #input field for guess
    read -r guess #reads input

    if [ $guess -lt $random_no ]; then #if guess is less than the number...
      echo "Too low!" #user is told number is too low
    elif [ $guess -gt $random_no ]; then #if guess is less than the number...
      echo "Too high!" #user is told number is too high
    else #if it isn't too low or too high...
      echo "Congratulations! $guess is correct!" #then the correct number was given
      break #new line
    fi #end if statement

    ((attempts--)) #decrement attempt count per try
    if [ $attempts -gt 0 ]; then #if attempts are higher than 0...
      echo "You have $attempts attempt(s) remaining." #user shown remaining attempts.
    else #if no attempts remain...
      echo "Out of attempts. The correct number was $random_no!"  #user told no more attempts / correct number given
    fi #end if statement
  done #complete game

  echo -n "Press Y to play again. Press any other key to exit: " #user told to input "Y" to continue
  read -r response #user inputs "Y"/"y" to continue or other character to exit.
  if [ $response != "Y" ] && [ "$response" != "y" ]; then #if input is not "Y" or "y", close program
    echo "Seeya." #notification of program termination
    break #new line
  fi #end if statement
done #close program
