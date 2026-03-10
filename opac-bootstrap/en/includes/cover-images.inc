[% USE raw %]
[% USE ItemTypes %]

<div class="bookcover"
     data-title="[% SEARCH_RESULT.title | html %]"
     data-author="[% SEARCH_RESULT.author | html %]"
     data-biblionumber="[% SEARCH_RESULT.biblionumber %]">

    <!-- Always render fallback cover -->
    <div class="generated-cover"
        data-title="[% SEARCH_RESULT.title | html %]">
        [% SEARCH_RESULT.title | truncate(40) %]
    </div>

    [% IF SEARCH_RESULT.has_local_cover_image
        || SEARCH_RESULT.normalized_isbn
        || SEARCH_RESULT.normalized_upc
        || SEARCH_RESULT.normalized_oclc %]

        <div
            class="cover-slider cover-slides itemtype_[% SEARCH_RESULT.itemtype | html %]"
            data-biblionumber="[% SEARCH_RESULT.biblionumber | html %]"
            data-title="[% SEARCH_RESULT.title | html %]"
            data-isbn="[% SEARCH_RESULT.normalized_isbn | html %]"
            data-isbn="[% To.json(SEARCH_RESULT.normalized_isbn) | $raw %]"
        >

            [% IF OPACLocalCoverImages && SEARCH_RESULT.has_local_cover_image %]
                <div class="cover-image local-coverimg">
                    <a href="/cgi-bin/koha/opac-image.pl?biblionumber=[% SEARCH_RESULT.biblionumber | uri %]">
                        <img src="/cgi-bin/koha/opac-image.pl?thumbnail=1&biblionumber=[% SEARCH_RESULT.biblionumber | uri %]" alt="Local cover image" />
                    </a>
                    <div class="hint">Local cover image</div>
                </div>
            [% END %]

            [% IF OPACAmazonCoverImages && SEARCH_RESULT.normalized_isbn %]
                <div class="cover-image amazon-coverimg">
                    <a href="https://images-na.ssl-images-amazon.com/images/P/[% SEARCH_RESULT.normalized_isbn | uri %].01.LZZZZZZZ.jpg">
                        <img
                            src="https://images-na.ssl-images-amazon.com/images/P/[% SEARCH_RESULT.normalized_isbn | uri %].01.MZZZZZZZ.jpg"
                            alt="Amazon cover image"
                            id="amazon-thumbnail-[% SEARCH_RESULT.biblionumber | html %]"
                        />
                    </a>
                    <div class="hint">Image from Amazon.com</div>
                </div>
            [% END %]

            [% IF SyndeticsCoverImages && SEARCH_RESULT.normalized_isbn %]
                <div class="cover-image syndetics-coverimg">
                    <img
                        src="https://secure.syndetics.com/index.aspx?isbn=[% SEARCH_RESULT.normalized_isbn | uri %]/[% SyndeticsCoverImageSize | uri %].GIF&amp;client=[% SyndeticsClientCode | uri %]"
                        alt="Syndetics cover image"
                    />
                    <div class="hint">Image from Syndetics</div>
                </div>
            [% END %]

            [% IF GoogleJackets %]
                <div class="cover-image googlejacket-coverimg">
                    <div class="[% SEARCH_RESULT.normalized_isbn | html %]" id="gbs-thumbnail-preview"></div>
                    <div class="hint">Image from Google Jackets</div>
                </div>
            [% END %]

            [% IF OpenLibraryCovers %]
                <div class="cover-image openlibrary-coverimg">
                    <div class="[% SEARCH_RESULT.normalized_isbn | html %]" id="openlibrary-thumbnail-[% SEARCH_RESULT.biblionumber | html %]"></div>
                    <div class="hint">Image from OpenLibrary</div>
                </div>
            [% END %]

        </div>

    [% END %]

</div>
