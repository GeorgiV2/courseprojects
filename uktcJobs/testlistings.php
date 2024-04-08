<!DOCTYPE html>
<html>
<head>
    <title>Job Listings</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-rbsA2VBKQhggwzxH7pPCaAqO46MgnOM80zW1RWuH61DGLwZJEdK2Kadq2F9CUG65" crossorigin="anonymous">
</head>
<body>

<div class="container mt-5">

<?php

include `functions.php`;

$conn = getDbConnection();
// Retrieve a list of jobs
$sql = 'SELECT * FROM jobs';
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // Output the data for each row
    while ($row = mysqli_fetch_assoc($result)) {
        echo '<div class="card mb-3">';
        echo '  <div class="card-body">';
        echo '    <h5 class="card-title">' . $row['company_name'] . '</h5>';
        echo '    <p class="card-text">Job Category: ' . $row['job_category'] . '</p>';
        echo '    <p class="card-text">Salary: ' . $row['salary'] . '</p>';
        echo '    <p class="card-text">Description: ' . $row['description'] . '</p>';
        echo '  </div>';
        echo '</div>';
    }
} else {
    echo '<p>No jobs found</p>';
}

mysqli_close($conn);

?>

</div>

</body>
</html>
