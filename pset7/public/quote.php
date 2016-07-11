<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
        {
            // else render form
            render("quote_form.php", ["title" => "Get quote"]);
        }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
        {
        //render("header.php", ["title" => "Quote"]);    
            
        $quote = lookup($_POST["quote"]);
         if($quote["symbol"] === null) {
             apologize("The quote doesn't exist");
         }   
         else{
             render("show_quote.php", ["name" => $quote["name"], "symbol" => $quote["symbol"], "price" => $quote["price"]]);
         }
         
         
        }
?>