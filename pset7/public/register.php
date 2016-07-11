<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        if(empty($_POST["password"]) || empty($_POST["confirmation"])){
            apologize("Are you sure you typed in your password twice?");
            
        }
        
        else if($_POST["password"] != $_POST["confirmation"]) {
            apologize("You didn't type the same password");
        }
        
        else {
            if(empty($_POST["username"])) {
                apologize("You didn't specify a username");
            }
            $result = CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
            if ($result === false) 
            {
                apologize("The specified username is taken");
            }
            else 
            {
                $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
                $id = $rows[0]["id"];
                
                
                $_SESSION["id"] = $id;
                redirect("../index.php");
            }
        }
    }

?>