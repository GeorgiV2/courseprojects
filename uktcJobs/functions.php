<?php
function getDbConnection()
{
    // Connect to the database
    $host = 'localhost';
    $user = 'root';
    $password = '';
    $database = 'uktcjobs';

    $conn = mysqli_connect($host, $user, $password, $database,'3307');

    if (!$conn) {
        die('Could not connect: ' . mysqli_connect_error());
    }

    return $conn;
}
?>