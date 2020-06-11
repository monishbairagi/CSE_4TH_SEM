----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   NOTgateDataFlow
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity NOTgateDataFlow is
    Port ( A : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end NOTgateDataFlow;

architecture dataflow of NOTgateDataFlow is
begin
	Y <= not A;
end dataflow;