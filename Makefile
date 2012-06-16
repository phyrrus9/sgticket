all:
	xcodebuild -target sgsign
	xcodebuild -target sgtk
	mv ./build/Release/sgsign ./binary
	mv ./build/Release/sgtk ./binary/sgrun
	rm -rf ./build
	cd skrun~iphone
	xcodebuild
	mv skrun~iphone/build/Release-iphoneos/skrun~iphone.app/skrun~iphone ./binary/sgrun~iphone
	rm -rf ./skrun~iphone/build

