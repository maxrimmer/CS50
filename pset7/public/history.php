<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT type, symbol, shares, price, time FROM history WHERE user_id = ?", $_SESSION["id"]);

    $positions = [];
    foreach ($rows as $row)
    {
        
        
        $positions[] = [
            "type" => $row["type"],
            "symbol" => strtoupper($row["symbol"]),
            "shares" => $row["shares"],
            "price" => $row["price"],
            "time" => $row["time"]
        ];
        
    }
    
    // render portfolio
    render("history_view.php", ["title" => "History", "positions" => $positions]);

?>
