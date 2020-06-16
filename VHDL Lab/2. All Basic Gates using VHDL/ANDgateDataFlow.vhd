----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   ANDgateDataFlow
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ANDgateDataFlow is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end ANDgateDataFlow;

architecture dataflow of ANDgateDataFlow is
begin
	Y <= A and B;
end dataflow;