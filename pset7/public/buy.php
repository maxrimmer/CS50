<?php

    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php");
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = $_POST["symbol"];
        $symbol = strtoupper($symbol);
        
        $quote = lookup($_POST["symbol"]);
         if($quote["symbol"] === null) {
             apologize("The quote doesn't exist");
         } 
         
        $shares = $_POST["shares"];
        if(!preg_match("/^\d+$/", $_POST["shares"])) {
            apologize("The number of shares should be an non negative integer");
        }
        
        $stock = lookup($symbol);
        $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $cash = $cash[0]["cash"];
        
        $cash_required = $stock["price"] * $shares;
        if($cash < $cash_required) {
            apologize("You don't have the money");
        }
        else if (false===CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cash_required, $_SESSION["id"])) {
            aplogize("Sorry, you don't have the money...");
        }
        
        else if(false === CS50:: query("INSERT INTO portfolio (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"])) {
            apologize("Are you sure you typed the right symbol?");
        }
        $transaction = 'buy';
        CS50::query("INSERT INTO history (user_id, symbol, shares, type, price) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $symbol, $shares, $transaction, $stock["price"]);
        redirect("/");
        
    }
    
?>