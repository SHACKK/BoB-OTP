<?php
	$rest = time() % 60;
	
	$key = time() - $rest;
	
	$salt = "BoB OTP";
	echo md5($salt, $key), "\n";
	
	$answer = substr(md5($key, $slat), -3, 3);
	
	if ( !isset($_SERVER['REMOTE_ADDR'] )) echo $answer , "\n";
	else if ( $_GET['key'] == $answer ) echo "Success";
?>

