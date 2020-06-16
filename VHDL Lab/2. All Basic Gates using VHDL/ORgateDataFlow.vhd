----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   ORgateDataFlow
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ORgateDataFlow is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end ORgateDataFlow;

architecture dataflow of ORgateDataFlow is
begin
	Y <= A or B;
end dataflow;