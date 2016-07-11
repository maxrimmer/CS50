<?php

    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("cash_form.php");
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["cash"] < 0) {
            apologize("You can't get negative cash");
        }
        else if ($_POST["cash"] > 1000) {
            apologize("No more than 1000$ a day");
        }
        else {
            if(false === CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["cash"], $_SESSION["id"])) {
                apologize("Something went wrong on our side");
            }
            else {
                redirect("/");
            }
        }
    }
    
?>