count = 0

File.open("User.txt", "r") do |f1|
	while line = f1.gets
		#puts line
		if line.include? "s"
			for	i in line
				#puts line
				count +=1
			end
		end
	end
end

print "Count = ", count, "\n"