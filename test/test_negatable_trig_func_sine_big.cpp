///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2015.
//  Copyright Nikhar Agrawal 2015.
//  Copyright Paul Bristow 2015.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)

//! \file
//!\brief Tests for the trogonometric sine function of (fixed_point) for a big digit range.

#include <array>
#include <cmath>
#include <string>

#define BOOST_TEST_MODULE test_negatable_trig_func_sine_big
#define BOOST_LIB_DIAGNOSTIC

#include <boost/fixed_point/fixed_point.hpp>
#include <boost/test/included/unit_test.hpp>

namespace local
{
  // Table[N[Sin[n / 10], 40], {n, 1, 127, 1}]
  const std::array<std::string, 128U> data =
  {{
    std::string("+0.0"),
    std::string("+0.0998334166468281523068141984106220269899"),
    std::string("+0.1986693307950612154594126271183897503702"),
    std::string("+0.2955202066613395751053207456850273736778"),
    std::string("+0.3894183423086504916663117567957052645931"),
    std::string("+0.4794255386042030002732879352155713880818"),
    std::string("+0.5646424733950353572009454456586579071099"),
    std::string("+0.6442176872376910536726143513987201830658"),
    std::string("+0.7173560908995227616271746105813853661928"),
    std::string("+0.7833269096274833884613823157135486231401"),
    std::string("+0.8414709848078965066525023216302989996226"),
    std::string("+0.8912073600614353399518025778717035383189"),
    std::string("+0.9320390859672263496701344354948259954151"),
    std::string("+0.9635581854171929647013486300395548153420"),
    std::string("+0.9854497299884601806594745788060975173563"),
    std::string("+0.9974949866040544309417233711414873227067"),
    std::string("+0.9995736030415051643421138255462341719795"),
    std::string("+0.9916648104524686153461333986478756524068"),
    std::string("+0.9738476308781951865323731788433576067029"),
    std::string("+0.9463000876874144884897096116349577621140"),
    std::string("+0.9092974268256816953960198659117448427023"),
    std::string("+0.8632093666488737706807593132690245849205"),
    std::string("+0.8084964038195901843040369104161190651586"),
    std::string("+0.7457052121767201773854062116434995389426"),
    std::string("+0.6754631805511509265657715253412833742534"),
    std::string("+0.5984721441039564940518547021861622717036"),
    std::string("+0.5155013718214642352577269352093682438939"),
    std::string("+0.4273798802338299345560530858578806474965"),
    std::string("+0.3349881501559049195438537527124221060303"),
    std::string("+0.2392493292139823281842569187395753722156"),
    std::string("+0.1411200080598672221007448028081102798469"),
    std::string("+0.0415806624332905791946982715966731005546"),
    std::string("-0.0583741434275799091372174146190951851251"),
    std::string("-0.1577456941432483820116542776024823708456"),
    std::string("-0.2555411020268313192499024293637390758109"),
    std::string("-0.3507832276896198481203688000436355850850"),
    std::string("-0.4425204432948523842667273474926939109185"),
    std::string("-0.5298361409084932132107776257012082698542"),
    std::string("-0.6118578909427190757335860861188824377161"),
    std::string("-0.6877661591839738180908881253786895610345"),
    std::string("-0.7568024953079282513726390945118290941359"),
    std::string("-0.8182771110644105042650370243584543824035"),
    std::string("-0.8715757724135880600185770979088212348077"),
    std::string("-0.9161659367494549840317093602846354670153"),
    std::string("-0.9516020738895159540353923333803876842052"),
    std::string("-0.9775301176650970553891350144986297778644"),
    std::string("-0.9936910036334644561381046599088295264215"),
    std::string("-0.9999232575641008841795365415749714463665"),
    std::string("-0.9961646088358406717815964665036345568219"),
    std::string("-0.9824526126243325122763772499183288400372"),
    std::string("-0.9589242746631384688931544061559939733525"),
    std::string("-0.9258146823277322969461462475448633125094"),
    std::string("-0.8834546557201532646730844404218032199939"),
    std::string("-0.8322674422239011635645596678545873241351"),
    std::string("-0.7727644875559873623584697827342323044571"),
    std::string("-0.7055403255703919062319191755220700788473"),
    std::string("-0.6312666378723213114636691537166711930720"),
    std::string("-0.5506855425976377612273506078724684007706"),
    std::string("-0.4646021794137572114182265267025893188526"),
    std::string("-0.3738766648302363598148464689833825796246"),
    std::string("-0.2794154981989258728115554466118947596280"),
    std::string("-0.1821625042720955400241283632246570156924"),
    std::string("-0.0830894028174965780005792890983671852811"),
    std::string("+0.0168139004843498903109663674940955687931"),
    std::string("+0.1165492048504932894804204887989452641633"),
    std::string("+0.2151199880878155242969457490747317395852"),
    std::string("+0.3115413635133781743549851055925936973028"),
    std::string("+0.4048499206165981616321928483868450184862"),
    std::string("+0.4941133511386083222220793776203418268838"),
    std::string("+0.5784397643881998701737832329888620145109"),
    std::string("+0.6569865987187890903969990915936351779369"),
    std::string("+0.7289690401258761520759857678531850987064"),
    std::string("+0.7936678638491530524644457476435822769907"),
    std::string("+0.8504366206285645175173662279669060444075"),
    std::string("+0.8987080958116267592694988965345551458093"),
    std::string("+0.9379999767747388579484637981490472364318"),
    std::string("+0.9679196720314864259034630180288175373812"),
    std::string("+0.9881682338770003685523936187236630214048"),
    std::string("+0.9985433453746049634387733205960908539565"),
    std::string("+0.9989413418397720363049105120438999227269"),
    std::string("+0.9893582466233817778081235982452886721164"),
    std::string("+0.9698898108450862432243199360998528644111"),
    std::string("+0.9407305566797729011536487499456463575502"),
    std::string("+0.9021718337562936400005044052529625313548"),
    std::string("+0.8545989080882806628332392814224102563187"),
    std::string("+0.7984871126234902866669131603391125858896"),
    std::string("+0.7343970978741131437171641875634528215641"),
    std::string("+0.6629692300821827922023461866155937327214"),
    std::string("+0.5849171928917622535309313118123751282594"),
    std::string("+0.5010208564578849820161746471113002012899"),
    std::string("+0.4121184852417565697562725663524351793439"),
    std::string("+0.3190983623493517707939976839854082313512"),
    std::string("+0.2228899141002469575280690577582775440868"),
    std::string("+0.1244544235070624079894062785863439352345"),
    std::string("+0.0247754254533581210797730773676051249713"),
    std::string("-0.0751511204618093072834825045340069376344"),
    std::string("-0.1743267812229799851241017265204181208473"),
    std::string("-0.2717606264109431243377408968248377700095"),
    std::string("-0.3664791292519277481692529487288563002372"),
    std::string("-0.4575358937753210444138181075053639260305"),
    std::string("-0.5440211108893698134047476618513772816836"),
    std::string("-0.6250706488928823649665268459128800146503"),
    std::string("-0.6998746875935428626333282630714186146977"),
    std::string("-0.7676858097635819782640158680187055000326"),
    std::string("-0.8278264690856534755103657343389460747048"),
    std::string("-0.8796957599716700980185086848259960346948"),
    std::string("-0.9227754216128067587526654282149708498612"),
    std::string("-0.9566350162701880736357075432209356251888"),
    std::string("-0.9809362300664914049937648600269240114949"),
    std::string("-0.9954362533063773698855455660135196973508"),
    std::string("-0.9999902065507034570515648990255221068430"),
    std::string("-0.9945525882039891635355030193988731645248"),
    std::string("-0.9791777291513172081292945078222165697142"),
    std::string("-0.9540192499020891876961521020108042052408"),
    std::string("-0.9193285256646758254368651787929763433981"),
    std::string("-0.8754521746884285269556855266063271366980"),
    std::string("-0.8228285949687086209101307651811581899701"),
    std::string("-0.7619835839190328189613070705262879944441"),
    std::string("-0.6935250847771228737089143477022058313719"),
    std::string("-0.6181371122370335791562688005220013711221"),
    std::string("-0.5365729180004349716653742282424017923157"),
    std::string("-0.4496474645346011512675440782002967108647"),
    std::string("-0.3582292822368280541849475942334352096503"),
    std::string("-0.2632317913658016506017078258880283863015"),
    std::string("-0.1656041754483097485505687782073186193986"),
    std::string("-0.0663218973512006889294098198634594272735"),
    std::string("+0.0336230472211370494393468648849711706207"),
    std::string("+0.1332320414199429163095796803235956213708"),
  }};
}

BOOST_AUTO_TEST_CASE(test_negatable_trig_func_sine_big)
{
  typedef boost::fixed_point::negatable<10, -117> fixed_point_type;
  typedef fixed_point_type::float_type            float_point_type;

  const fixed_point_type tol = ldexp(fixed_point_type(1), fixed_point_type::resolution + 12);

  for(int i = 1; i < 128; ++i)
  {
    const fixed_point_type x = sin(fixed_point_type(i) / 10);
    const float_point_type y = float_point_type(local::data[i]);

    BOOST_CHECK_CLOSE_FRACTION(x, fixed_point_type(y), tol);
  }
}
