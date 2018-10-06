<cfscript>
		/*
			Given an array with a possibly infinate amount of nested arrays, 
			as ColdFusion does not have a function to flatten arrays.
			
			Example: 
				Input: [
					1, [
						2, 3, [
							4, 5, [
								6
							]
						]
					]
				]
				
				Output: [1, 2, 3, 4, 5, 6]
		*/

		public array function flattenArray(required array arr) {
			var items = [];

			arr.each(function(item) {
				if (isArray(item)) {
					items.addAll(flattenArray(item));
				} else {
					items.append(item);
				}
			});

			return items;
		}
</cfscript>
