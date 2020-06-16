----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   NORgateDataFlow
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity NORgateDataFlow is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end NORgateDataFlow;

architecture dataflow of NORgateDataFlow is
begin
	Y <= A nor B;
end dataflow;