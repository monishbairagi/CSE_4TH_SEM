----------------------------------------------------------------------------------
-- Engineer:       Monish Kumar Bairagi
-- Project Name:   fourBitALU
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity ALUfourBit is
	Port(a : in STD_LOGIC_VECTOR(3 downto 0);
	     b : in STD_LOGIC_VECTOR(3 downto 0);
	     sel : in STD_LOGIC_VECTOR(2 downto 0);
	     out_alu : out STD_LOGIC_VECTOR(3 downto 0)
             );
end ALUfourBit;

architecture Behavioral of ALUfourBit is
begin
process(a,b,sel)
	begin
		case sel is
			when "000" => out_alu <= a + b;
			when "001" => out_alu <= a - b;
			when "010" => out_alu <= a - 1;
			when "011" => out_alu <= a + 1;
			when "100" => out_alu <= a and b;
			when "101" => out_alu <= a or b;
			when "110" => out_alu <= not a;
			when "111" => out_alu <= a xor b;
			when others => NULL;
		end case;
end process;
end Behavioral;