<?php

    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell_form.php");
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    $rows = CS50::query("SELECT shares FROM portfolio WHERE user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));

    if(CS50::query("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]) === false) {
            apologize("You don't own this stock");
        }
        
        $stock = lookup($_POST["symbol"]);
        
        if (count($rows) == 1) {
            $userShares = $rows[0]["shares"];
        }
        else {
            apologize("Nah, you don't have these shares mate!");
        }
        $new_cash = $stock["price"] * $userShares;
        
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $new_cash, $_SESSION["id"]);
        
        $transaction = 'sell';
        CS50::query("INSERT INTO history (user_id, symbol, shares, type, price) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $_POST["symbol"], $userShares, $transaction, $stock["price"]);

        redirect("/");
    }
    
?>